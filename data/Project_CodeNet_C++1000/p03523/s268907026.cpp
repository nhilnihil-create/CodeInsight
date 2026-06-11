#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int main(){
    string S;
    cin >> S;
    
    map<char, int> cnt;
    for(char c = 'A'; c <= 'Z'; ++c){
        cnt[c] = 0;
    }
    for(int i = 0; i < S.length(); ++i){
        cnt[S[i]]++;
    }
    for(char c = 'A'; c <= 'Z'; ++c){
        if(c == 'A'){
            if(cnt[c] > 4){
                cout << "NO\n";
                return 0;
            }
        }
        else if(c == 'K' || c == 'I' || c == 'H' || c == 'B' || c == 'R'){
            if(cnt[c] != 1){
                cout << "NO\n";
                return 0;
            }
        }
        else{
            if(cnt[c] > 0){
                cout << "NO\n";
                return 0;
            }
        }
    }
    
    int id1, id2, id3;
    id1 = S.find("KIH");
    id2 = S.find("B");
    id3 = S.find("R");
    
    if(id1 == string::npos || id2 == string::npos || id3 == string::npos){
        cout << "NO\n";
        return 0;
    }
    if(id1 > id2 || id1 > id3 || id2 > id3){
        cout << "NO\n";
        return 0;
    }
    
    if(id1 > 1){
        cout << "NO\n";
        return 0;
    }
    if(id2 - id1 > 4){
        cout << "NO\n";
        return 0;
    }
    if(id3 - id2 > 2){
        cout << "NO\n";
        return 0;
    }
    if(S.length() - id3 > 2){
        cout << "NO\n";
        return 0;
    }
    
    cout << "YES\n";
}