#include <bits/stdc++.h>
#define meow(args...) fprintf(stderr, args)
template<class T1, class T2> inline bool cmin(T1 &a, const T2 &b) {return b<a?(a=b, true):false;}
template<class T1, class T2> inline bool cmax(T1 &a, const T2 &b) {return a<b?(a=b, true):false;}
template<class Type> Type read() {
	Type a;
	bool b;
	unsigned char c;
	while(c=getchar()-'0', (c>9)&(c!=253));
	for(a=(b=c==253)?0:c; (c=getchar()-'0')<=9; a=a*10+c);
	return b?-a:a;
}
int (*rd)()=read<int>;
int main() {
	int n=rd();
	std::vector<int> size(n, 1), fa(n);
	std::vector<long long> depsum(n);
	std::map<long long, int> id;
	for(int i=0; i<n; ++i) id.emplace(read<long long>(), i);
	for(auto it=id.end(); --it!=id.begin(); ) {
		int x=it->second;
		auto i=id.find(it->first+2*size[x]-n);
		if(2*size[x]>=n||i==id.end()) {
			puts("-1");
			return 0;
		}
		fa[x]=i->second;
		size[fa[x]]+=size[x];
		depsum[fa[x]]+=depsum[x]+size[x];
	}
	int root=id.begin()->second;
	if(depsum[root]!=id.begin()->first) {
		puts("-1");
		return 0;
	}
	for(int i=0; i<n; ++i) if(i!=root) printf("%d %d\n", fa[i]+1, i+1);
	return 0;
}
