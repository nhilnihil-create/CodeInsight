#include <iostream>

using namespace std;
int main(){
    string s;
    cin >> s;
    int sum =0 ;
    for(auto c:s){
        if(c == '1'){
            sum++;
        }
    }
    cout << sum << endl;
}