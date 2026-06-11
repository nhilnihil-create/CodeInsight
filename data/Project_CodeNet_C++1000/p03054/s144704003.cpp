// Created by sz
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int h,w,n,sr,sc;
string s,t;


int main(){
#ifdef LOCAL
    freopen("./input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>h>>w>>n>>sr>>sc;
    cin>>s>>t;
    
    //up
    int up_to = sr;
    int down_to = sr;
    for (int i = 0; i < n; i++){
        if(s[i] == 'U'){
            up_to --;
            if(up_to ==0){
                cout<<"NO"<<endl;
                return 0;
            }
        }
        if(s[i] == 'D'){
            down_to ++;
            if(down_to == h+1){
                cout<<"NO"<<endl;
                return 0;
            }
        }
        
        if(t[i] == 'D'&& up_to<h){
            up_to ++;
        }
        
        if(t[i]=='U'&& down_to >1){
            down_to --;
        }
    }
    
    int left_to = sc, right_to = sc;
    
    for (int i = 0; i < n; i++){
        if(s[i] == 'L'){
            left_to --;
            if(left_to == 0){
                cout<<"NO"<<endl;
                return 0;
            }
        }
        
        if(s[i] == 'R'){
            right_to ++;
            if(right_to == w+1){
                cout<<"NO"<<endl;
                return 0;
            }
        }
        
        if(t[i] == 'R'&& left_to<w ){
            left_to++;
        }
        
        if(t[i] == 'L'&&right_to > 1){
            right_to --;
        }
        
    }
    
    
    
    cout<<"YES"<<endl;
    
    
    
    return 0;
}

