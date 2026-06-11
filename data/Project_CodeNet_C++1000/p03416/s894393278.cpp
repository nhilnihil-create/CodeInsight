#include<bits/stdc++.h>
#define endl '\n'
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define mod 1000000007
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
#define REP(i,a,b) for(int i=a;i<b;i++)
#define maxx 1000001
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

bool palindrome(int n){
   string s=to_string(n),ss,t;
   int sz=s.size();
   for(int i=0;i<sz/2;i++){
     if(s[i]!=s[sz-i-1]) return 0;
   }
   return 1;
}

int main() {
    FASTIO
    int a,b,cnt=0;
    cin>>a>>b;
    for(int i=a;i<=b;i++){
        if(palindrome(i)) cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}
