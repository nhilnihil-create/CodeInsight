#include <iostream>
#include <string>
#define ll long long
using namespace std;
int main(){
    int n, arr[100005], modo=1e9+7;
    ll s=1;
    string a;
    cin >> n >> a;
    for(int i=0; i<a.size(); i++){
        arr[a[i]]++;
    }
    for(int i='a'; i<='z'; i++){
        if(arr[i]>0){
            s*=(arr[i]+1);
            s%=modo;
        }
    }
    s--;
    cout << s << endl;
}
