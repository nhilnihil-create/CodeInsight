#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    string s;cin>>s;
    s.replace(4,1,"0");
    s.replace(7,1,"0");
    if(s<="2019004030")cout<<"Heisei"<<endl;
    else cout<<"TBD"<<endl;
	return 0;
}