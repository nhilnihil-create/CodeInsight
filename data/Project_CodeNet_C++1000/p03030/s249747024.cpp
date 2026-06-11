#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;


//read_kaisetsu
int main() {
    int n;cin>>n;
    pair<pair<string,int>,int> p[101];
    rep(i,n){
        string s;
        int q;
        cin>>s>>q;
        p[i] = make_pair(make_pair(s,-q),i);
    }
    sort(p, p+n);
    rep(i,n)cout<<p[i].second + 1<<endl;
	return 0;
}