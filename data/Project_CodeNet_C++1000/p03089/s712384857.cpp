#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n, arr[105], ar[105], k, z=0, x;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> arr[i];
    }
    for(int i=n; i>=1; i--){
        k=i;
        x=i;
        while(x>=1 && arr[x]!=x){
            x--;
        }
        if(arr[x]==x){
            ar[k]=arr[x];
            for(int j=x; j<=i; j++){
                arr[j]=arr[j+1];
            }
        }
        else{
            x=-1;
            cout << x << endl; 
            return 0;
        }
    }
    for(int i=1; i<=n; i++){
        cout << ar[i] << endl;
    }
    return 0;
}