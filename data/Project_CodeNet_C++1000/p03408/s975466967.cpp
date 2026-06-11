#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int N,M,res;
    string str;
    res = 0;
 
    cin >> N;
 
    map<string,int> B;   
    
    for(int i = 0; i < N; i++){
        cin >> str;
        B[str]++;
    }
    
    cin >> M;
 
    for(int i = 0; i < M; i++){
        cin >> str;
        B[str]--;
    }
 
  	map<string,int>:: iterator iter;
    for(iter = B.begin(); iter != B.end(); iter++){
        res = max(res,iter->second);
    }
 
    cout << res << endl;
    return 0;
}