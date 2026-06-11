#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int N,M,count=0;
    cin>>N;
    vector<string> s(N);
    for(int i=0;i<N;++i)cin>>s[i];
    
    cin>>M;
    vector<string> t(M);
    for(int i=0;i<M;++i)cin>>t[i];

        auto calc=[&](string find){
            int buf=0;
                for(string word:s){
                    if(word==find)buf++;
                }
                for(string word:t){
                    if(word==find)buf--;
                }
            return buf;
        };

                    for(string word : s ){
                        count=max(count,calc(word));
                    }

        cout<<count;


}