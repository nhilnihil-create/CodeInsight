#include <bits/stdc++.h>
using namespace std;

int main(void){
   
    int N;
    cin >> N;
    map<string,int>mp{};
    
    char b;
    string w_i;
    cin >> w_i;
    mp[w_i] = 1;
    b = w_i[w_i.size()-1];
    
    for(int i=1;i<N;i++){
        cin >> w_i;
        if(w_i[0] == b && mp.count(w_i) == 0){
            mp[w_i] = 1;
            b = w_i[w_i.size()-1];
        }
        else{
            cout << "No" <<endl;
            return 0;
        }
    }
    
    cout << "Yes" <<endl;
}
