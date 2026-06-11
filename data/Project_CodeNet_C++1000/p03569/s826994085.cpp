#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int main(){
    string s;
    cin>>s;
    int n=s.size();
    int res=0;
    for(int i=0,j=s.size()-1;i<j;){
        if(s[i]==s[j]) i++,j--;
        else if(s[i]=='x') res++,i++;
        else if(s[j]=='x') res++,j--;
        else{
            cout<<-1<<endl;
            return 0;
        }
    }

    cout<<res<<endl;

}
