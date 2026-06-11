#include <iostream>
#include <string>
#include <algorithm> 
#include <cstdlib>
#include <map>
#include <queue>
#include <vector>
#include <cmath>
#include <limits>
#define ll long long
using namespace std;
int main(){
    string s;
    cin >> s;
    int a=0,b=0,c=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='a'){
            a++;
        }else if(s[i]=='b'){
            b++;
        } else{
            c++;
        }
    }
    if(abs(a-b)<=1&&abs(b-c)<=1&&abs(c-a)<=1){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    }