#include <iostream>
#include <algorithm>
using namespace std;
bool descending(int a, int b){
    if(a > b){
        return true;
    }
    else {
        return false;
    }
}
int main(){
    int n, h, a[100005], b[100005], maxa=0, c=0, x=0;;
    cin >> n >> h;
    for(int i=0; i<n; i++){
        cin >> a[i] >> b[i];
        if(maxa<a[i]){
            maxa=a[i];
        }
    }
    sort(b, b+n, descending);
    while(h>0){
        if(b[c]>=maxa && c<n){
            h-=b[c];
            c++;
            x++;
        }
        else{
            h-=maxa;
            x++;
        }
    }
    cout << x << endl;
    return 0;
}