#include <iostream> 
#include <string> 
#define ll long long
using namespace std;
int main(){
    ll score=0;
    int x=0;
    string a;
    cin >> a;
    for(int i=0; i<a.size(); i++){
        if(a[i]=='B'){
            x++;
        }
        else{
            score+=x;
        }
    }
    cout << score << endl;
    return 0;
}