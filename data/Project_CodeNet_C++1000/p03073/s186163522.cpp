#include<iostream>
#include<cmath>
#include<vector>
#include<bitset>
#include<bitset>
#include<string>
#include<utility>
#include<queue>

using namespace std;

int main(){
    string s;
    cin >> s;
    int ansa=0,ansb=0;
    for(int i=0;i<s.size();i++){
        if(i&1){
            if(s.at(i)=='0'){
                ansa++;
            }else{
                ansb++;
            }
        }else{
            if(s.at(i)=='0'){
                ansb++;
            }else{
                ansa++;
            }
        }
        
    }
    cout << min(ansa,ansb) << endl;
    return 0;
}