#include <bits/stdc++.h>
using namespace std;
 int h, w;
 
bool check(int i, int j){
    if(i >= 0 && i < h && j >= 0 && j < w) return true;
    return false;
}

int main(){
    
    cin >> h >> w;
    
    vector<string>a(h);
    
    for(int i = 0; i < h; i++){
        cin >> a[i];
    }
    
    
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(a[i][j] == '#'){
                if(check(i-1, j)){
                    if(a[i-1][j] == '#'){
                        continue;
                    }
                }
                if(check(i, j-1)){
                    if(a[i][j-1] == '#'){
                        continue;
                    }
                }
                if(check(i+1, j)){
                    if(a[i+1][j] == '#'){
                        continue;
                    }
                }
                if(check(i, j+1)){
                    if(a[i][j+1] == '#'){
                        continue;
                    }
                }
                cout << "No" << endl;
                return 0;
                
            }
        }
    }
    cout << "Yes" << endl;
    
    
}
