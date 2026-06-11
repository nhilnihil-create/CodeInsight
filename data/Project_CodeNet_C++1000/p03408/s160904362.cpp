#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int N,M,max,tmp;
    string str;
    max = 0;
    tmp = 0;
 
    cin >> N;
 
    map<string,int> B;
    map<string,int> R;
    
    
    for(int i = 0; i < N; i++){
        cin >> str;
        B[str]++;
    }
  
  	cin >> M;
 
    for(int i = 0; i < M; i++){
        cin >> str;
        R[str]++;
    }
 
    auto begin = B.begin(), end = B.end();
 
    for(auto iter = begin; iter != end; iter++){
        tmp = B[iter->first] - R[iter->first];
        if(tmp > max) max = tmp;
        tmp = 0;
    }
    
    cout << max << endl;
 
    return 0;
}