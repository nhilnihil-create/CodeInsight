#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n];
    cin >> a[0];
    int MIN=a[0];
    int MAX=a[0];
    int max_p=0;
    int min_p=0;
    for(int i=1;i<n;i++){
        cin >> a[i];
        if(a[i]<MIN){
            min_p=i;
            MIN=a[i];
        }
        if(MAX<a[i]){
            max_p=i;
            MAX=a[i];
        }
    }
    if(MIN>=0){
        cout << n-1 << endl;
        for(int i=1;i<n;i++)cout << i << " " << i+1 << endl;
        return 0;
    }
    else if(MAX<=0){
        cout << n-1 << endl;
        for(int i=n;i>1;i--)cout << i << " " << i-1 << endl;
        return 0;
    }
    else if(abs(MAX)>=abs(MIN)){
        cout << 2*n-2 << endl;
        for(int i=0;i<n;i++)if(i!=max_p)cout << max_p+1 << " " << i+1 << endl;
        for(int i=1;i<n;i++)cout << i << " " << i+1 << endl;
        return 0;
    }
    else{
        cout << 2*n-2 << endl;
        for(int i=0;i<n;i++)if(i!=min_p)cout << min_p+1 << " " << i+1 << endl;
        for(int i=n;i>1;i--)cout << i << " " << i-1 << endl;
    }
}