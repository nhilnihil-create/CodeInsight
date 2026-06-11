#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define YN(x) cout<<(bool x?"Yes":"No")<<endl;
#define out(s) cout<<s<<endl;
#define pb push_back;
#define sp " ";
void vout(vector<int> v){
    for(int i=0;i<v.size();i++)
    cout<<v.at(i)<<endl;
}
int main(){
    string s,t;
    int start;
    bool check=false;
    cin>>s>>t;
    rep(i,s.size()-t.size()+1){
        for(int j=i;j<i+t.size();j++){
            if(s.at(j)==t.at(j-i)||s.at(j)=='?'){
                if(j==i+t.size()-1){

                    check=true;
                    start=i;
                    break;
                }
                else{
                    continue;
                }
                
            }
            else{
                break;
            }
        }
    }
    if(check){
        for(int i=start;i<start+t.size();i++){
            s.at(i)=t.at(i-start);
        }
        rep(i,s.size()){
            if(s.at(i)=='?'){
                s.at(i)='a';
            }   
        }
        cout<<s;
    }
    else{
        cout<<"UNRESTORABLE";
    }
}