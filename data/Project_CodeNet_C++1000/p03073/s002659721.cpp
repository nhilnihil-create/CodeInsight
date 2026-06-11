#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string Made_Model(int size, char s){
    
    string result = "";
    for(int i=0;i<size;i++){
        if(i%2 == 0){
            result += s;
        }
        else{
            if(s == '0') result += '1';
            else result += '0';
        }
    }
    return result;
}

int Diff(string s, string t){
    
    int l = s.size();
    int sum = 0;
    for(int i=0;i<l;i++){
        if(s[i] != t[i]) sum++;
    }
    
    return sum;
}
int main(){

    string S;
    cin >> S;
    int len = S.size();
    cout << min(Diff(S,Made_Model(len,'0')),Diff(S,Made_Model(len,'1'))) << endl;
}