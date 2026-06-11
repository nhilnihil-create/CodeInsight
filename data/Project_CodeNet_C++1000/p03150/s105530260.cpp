#include <iostream>
using namespace std;
int main(void){
    string s;
    cin >> s;
    
    for(int i = 0;i < s.size();i++){
          for(int j = s.size()-i;j >=0;j--){
                string t = s;
                string u = t.replace(i,j,"");
                if(u == "keyence"){
                      cout <<"YES" << endl;
                      return 0;
                }
                
          }
    }
    cout << "NO" << endl;
}
