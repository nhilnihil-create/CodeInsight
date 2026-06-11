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
    int size = s.size();
    if(size%3!=0){
      size = size/3 + 1;
    }else{
      size = size/3;
    }
    if(a<=size&&b<=size&&c<=size){
      cout << "YES" << endl;
    }else{
      cout << "NO" << endl;
    }
}
