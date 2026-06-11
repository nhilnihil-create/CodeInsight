#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <cassert>
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define srep(i,n,m) for(int i=n;i<m;i++)
#define elif else if
#define INF 1000000007
#define pi 3.141592653589793
using namespace std;
int saidaikouyakusuu(int a,int b){
    if(b==0) return a;
    return saidaikouyakusuu(b,a%b);
}
int saisyoukoubaisuu(int a,int b){
    return a*b/saidaikouyakusuu(a,b);
}
int n,m,cnt=0,aa[220000],ans=0,x,y,ab[220000];
pair<int,int> pp[220000];
string s,ss[220000];
char c;
queue<int> que;
signed main(){
    cin>>s;
    if(s[0]!='A'||s[1]<'a'){
        cout<<"WA"<<endl;
    }else{
        for(int i=2;i<s.size()-1;i++){
            if(s[i]=='C'){
                cnt++;
            }
        }
        if(cnt!=1){
            cout<<"WA"<<endl;
            return 0;
        }
        for(int i=2;i<s.size()-1;i++){
            if(s[i]!='C'&&s[i]<'a'){
                cout<<"WA"<<endl;
                return 0;
            }
        }
        if(s[s.size()-1]<'a'){
            cout<<"WA"<<endl;
            return 0;
        }
        cout<<"AC"<<endl;
    }
}