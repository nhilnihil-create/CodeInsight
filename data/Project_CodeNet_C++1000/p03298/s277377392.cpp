#include<bits/stdc++.h>
using namespace std;
namespace whatever{
	int readu(){
		char ch=getchar();
		while(!isdigit(ch))
			ch=getchar();
		int value=ch-'0';
		ch=getchar();
		while(isdigit(ch)){
			value=value*10+ch-'0';
			ch=getchar();
		}
		return value;
	}
	void writeull(long long n){
		if(n<10)
			putchar(n+'0');
		else{
			writeull(n/10);
			putchar(n%10+'0');
		}
	}
	auto generate(string str, int n){
		map<pair<string, string>, int> result;
		for(int s=0; s<(1<<n); ++s){
			string r;
			string b;
			for(int i=0; i<n; ++i)
				if(s&(1<<i))
					r.push_back(str.at(i));
				else
					b.push_back(str.at(i));
			reverse(b.begin(), b.end());
			++result[make_pair(r, b)];
		}
		return result;
	}
	void run(){
		int n=readu();
		string s;
		cin>>s;
		string left_str(s.substr(0, n));
		auto left(generate(left_str, n));
		string right_str(s.substr(n));
		reverse(right_str.begin(), right_str.end());
		auto right(generate(right_str, n));
		long long result=0;
		for(auto cur: left){
			int cur_cnt=cur.second;
			string r=cur.first.first;
			string b=cur.first.second;
			result+=(long long)cur_cnt*right[make_pair(r, b)];
		}
		writeull(result);
		putchar('\n');
	}
}
int main(){
	whatever::run();
}