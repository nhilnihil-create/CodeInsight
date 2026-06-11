#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int N,M,max,tmp;
    string str;
    max = 0;
    tmp = 0;
  
    map<string,int> B;
    map<string,int> R;
 
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> str;
        B[str]++;
    }
  
 	cin >> M;
    for(int i = 0; i < M; i++){
        cin >> str;
        R[str]++;
    }
 
    for(auto iter = B.begin(); iter != B.end(); iter++){
        if(R.count(iter->first)){
             tmp = B[iter->first] - R[iter->first];
        }else{
            tmp = B[iter->first];
        }
       
        if(tmp > max) max = tmp;
        tmp = 0;
    }
    
    cout << max << endl;
    return 0;
}