#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(){
    int N,M;
    string s[110],t[110];
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>s[i];
    }
    cin>>M;
    for(int i=0;i<M;i++){
        cin>>t[i];
    }
    map<string,int> d;
    for(int i=0;i<N;i++){
        d[s[i]] += 1;
    }
    for(int i=0;i<M;i++){
        d[t[i]] -= 1;
    }
    int max = 0;
    for(int i=0;i<N;i++){
        if(max<d[s[i]]){
            max = d[s[i]];
        }
    }
    cout<<max<<endl;
}