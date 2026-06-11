#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define inf 1001001001001001001
#define mod 1000000007
#define mod2 998244353
#define pi acos(-1)
#define all(v) v.begin(),v.end()

int main(){
    int N;cin>>N;
    string s;cin>>s;
    string str1="";
    string str2="";
    int max=0;
    int count;
    set<char>s1,s2;
    for(int i=1;i<N;i++){
        count=0;
        for(int j=0;j<i;j++){
            s1.insert(s.at(j));
        }
        for(int j=i;j<N;j++){
            s2.insert(s.at(j));
        }
        for(auto value:s1){
            if(s2.count(value)){
                count++;
            }
        }
        if(max<=count)max=count;
        s1.clear();
        s2.clear();
        
    }
    cout<<max<<endl;
}