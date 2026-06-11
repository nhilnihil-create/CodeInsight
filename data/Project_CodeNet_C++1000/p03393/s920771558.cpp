#define _LIBCPP_DEBUG 0
#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=int(a);i<int(b);i++)
typedef vector<int> vi;
typedef long long ll;



int main(){
    string s;cin>>s;
    if(s=="zyxwvutsrqponmlkjihgfedcba"){
        cout<<-1<<endl;
        return 0;
    }
    int N=s.size();
    if(N!=26){
        cout<<s;
        map<char,int> m;
        for(char i='a';i<='z';i++){
            m[i]=0;
        }
        rep(i,0,N){
            m[s.at(i)]++;
        }
        for(auto it:m){
            if(it.second==0){
                cout<<it.first;
                return 0;
            }
        }
    }
    else{
        map<char,int> m;
        rep(i,0,N){
            m[s.at(i)]=i;
        }
        for(int i=25;i>=0;i--){
            char tmp=s.at(i);
            while(tmp<='z'){
                tmp++;
                if(m[tmp]>=i){
                    rep(j,0,i){
                        cout<<s.at(j);
                    }
                    cout<<tmp;
                    return 0;
                }
            }
        }
    }

    
}




