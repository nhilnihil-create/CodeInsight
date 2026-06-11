#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <utility>
#include <set>
#include <stack>
#include <climits>
#include <cmath>

#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define rep1(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
#define reps(i,s,n) for(int i=s, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define MEMSET(v, h) memset((v), h, sizeof(v))
typedef long long ll;
const char sp = ' ';


using namespace std;

int main(void){
    string s;
    cin>>s;
    ll a=0, bc=0, flag=0;
    ll index=0;
    ll count=0;
    while(index<s.size()){
        if(flag==0){
            if(s[index]=='A') a++;
            else{
                if(index+1<s.size()){
                    if(s[index]=='B' && s[index+1]=='C') flag=1;
                        else a=0;
                }
                else a=0;
            }
        }
        if(flag==1){
            if(index+1<s.size()){
                if(s[index]=='B' && s[index+1]=='C') bc++;
                else{count+=a*bc; bc=0; flag=0;}
            }
            else{count+=a*bc; bc=0; flag=0;}
            if(s[index]=='A') continue;
         }
        index++;
    }
    cout<<count<<endl;
    return 0;
}
