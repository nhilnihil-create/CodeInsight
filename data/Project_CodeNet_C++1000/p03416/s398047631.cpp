#include<iostream>
using namespace std;

bool isKaibun(int n){
    string s = to_string(n);
    for(int i = 0; i < s.size()/2; i++){
        if(s.at(i) != s.at((s.size()-1)-i))return false;
    }
    return true;
}

int main(){
    int A,B;
    cin >> A >> B;

    int count = 0;
    for(int i = A; i <= B; i++){
        if(isKaibun(i))count++;
    }
    cout << count << endl;
    return 0;
}