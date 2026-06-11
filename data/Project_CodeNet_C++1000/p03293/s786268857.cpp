#include <iostream>
using namespace std;
int main(void){
    string s,t;
    cin >> s;
    cin >> t;
    
    s += s;
    for(int i = 0;i < t.size();i++){
          if(s.substr(i,t.size()) == t){
                cout << "Yes" << endl;
                return 0;
          }
    }
    cout << "No" << endl;
}
