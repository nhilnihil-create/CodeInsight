#include <bits/stdc++.h>
using namespace std;

int main(){
    int m, n;
    cin >> m >> n;
    char arr[m][n];
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }
    int val{0};
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            val = 0;
            if(arr[i][j] == '.'){
                if(j>0){
                if(arr[i][j-1]=='#'){
                        val++;
                }
                }
                if(j<(n-1)){
                if(arr[i][j+1]=='#'){
                        val++;
                }
                }
                if(i>0){
                    if(arr[i-1][j]=='#'){
                        val++;
                    }
                    if(j>0){
                        if(arr[i-1][j-1]=='#'){
                        val++;
                        }
                        
                        
                    }
                    if(j<(n-1)){
                        if(arr[i-1][j+1]=='#'){
                        val++;
                        }
                        
                    }
                }
                if(i<(m-1)){
                    if(arr[i+1][j]=='#'){
                        val++;
                    }
                    if(j>0){
                        if(arr[i+1][j-1]=='#'){
                        val++;
                        }
                        
                    }
                    if(j<(n-1)){
                        if(arr[i+1][j+1]=='#'){
                        val++;
                        }
                    }
                }
                val+=48;
                arr[i][j] = val;
            }
        }
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout << arr[i][j];
        }
        cout << endl;
    }
}