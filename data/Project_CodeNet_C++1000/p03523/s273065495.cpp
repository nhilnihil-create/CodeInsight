#include <bits/stdc++.h>
using namespace std;
 
int main(){
    string S;
    cin >> S;
    
    // *KIH*B*R*
    vector<string> vec;
    vec.push_back("KIHBR");     // 0000
    vec.push_back("KIHBRA");    // 0001
    vec.push_back("KIHBAR");     // 0010
    vec.push_back("KIHBARA");     // 0011
    vec.push_back("KIHABR");     // 0100
    vec.push_back("KIHABRA");     // 0101
    vec.push_back("KIHABAR");     // 0110
    vec.push_back("KIHABARA");     // 0111
    vec.push_back("AKIHBR");     // 1000
    vec.push_back("AKIHBRA");    // 1001
    vec.push_back("AKIHBAR");     // 1010
    vec.push_back("AKIHBARA");     // 1011
    vec.push_back("AKIHABR");     // 1100
    vec.push_back("AKIHABRA");     // 1101
    vec.push_back("AKIHABAR");     // 1110
    vec.push_back("AKIHABARA");     // 1111

    for(int i=0;i<vec.size();i++){
        if(S == vec[i]){
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;

}