#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i < (n); i++)
using namespace std;
using ll = long long;


int main(){
    int N,K;
    cin >> N >> K;
    string s;
    cin >> s;
    
    vector<int> num;
    num.push_back(0);
    num.push_back(0);
    for(int i=0; i<s.size()-1; i++){
        if(s[i] != s[i+1]){
            num.push_back(i+1);
        }
    }
    num.push_back(N);
    num.push_back(N);
    
    int max111=0;
    if(s[0]=='1'){
        int i=1,x=0;;
        
        while(i+2*K+1< num.size()){
            x=0;
            x = num[i+2*K+1] - num[i];
            i +=2;
            //cout << "x: " <<x << endl;
            max111=max(max111, x);
        }
    }
    
    if(s[0]=='0'){
        int i=0,x=0;;
        
        while(i+2*K+1< num.size()){
            x=0;
            x = num[i+2*K+1] - num[i];
            i +=2;
            //cout << "x: " <<x << endl;
            max111=max(max111, x);
        }
    }
    
    
    if(2*K+1 >= num.size()-2) max111=N;
    
    cout << max111 << endl;
    
    
    /*
    for(int x:num){
        cout << x << " ";
    }cout << endl;
    */
    
}
