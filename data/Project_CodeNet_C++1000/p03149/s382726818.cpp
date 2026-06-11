#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(long long i=0; i<(long long)(n);i++)
#define rep2(i,s,n) for(long long i=(s); i<(long long)(n);i++)
#define mod 1000000007

int main() {
    vector<int>s(4);
    cin>>s[0]>>s[1]>>s[2]>>s[3];

    sort(s.begin(),s.end());
    if(s[0]==1&&s[1]==4&&s[2]==7&&s[3]==9){
        cout<<"YES"<<endl;
    }
    else {
        cout<<"NO"<<endl;
    }

}
