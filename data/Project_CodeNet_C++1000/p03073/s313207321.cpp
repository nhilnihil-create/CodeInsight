#include <bits/stdc++.h>
using namespace std;
 
int main() {
    string S;
    cin >>S;
        int count=0;
        int countb=0;
    if(S.size()%2==0){
        for(int i=0;i<S.size();i+=2){
            if(S.at(i)=='0'){
                count++;
            }
            if(S.at(i+1)=='1'){
                count++;
            }
        }
        for(int i=0;i<S.size();i+=2){
            if(S.at(i)=='1'){
                countb++;
            }
            if(S.at(i+1)=='0'){
                countb++;
            }
        }
    }
    else{
        for(int i=0;i<S.size();i+=2){
            if(S.at(i)=='1'){
                count++;
            }
        }
        for(int i=1;i<S.size();i+=2){
            if(S.at(i)=='0'){
                count++;
            }
        }
        for(int i=0;i<S.size();i+=2){
            if(S.at(i)=='0'){
                countb++;
            }
        }
        for(int i=1;i<S.size();i+=2){
            if(S.at(i)=='1'){
                countb++;
            }
        } 
    }
    cout <<min(count,countb)<<endl;
    
}