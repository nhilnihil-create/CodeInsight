#include <iostream>
#include <vector>
#include <functional>
#include <iomanip>
int MOD=1e9+7;
using namespace std;
int main(){
    string n;
    cin >> n;
    int count=0;
    for(int i=0;i<4;i++){
        if(n[i]=='2'){
            count++;
        }
    }
    cout<<count<<endl;
}
