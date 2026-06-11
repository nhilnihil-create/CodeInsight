#include<bits/stdc++.h>

using namespace std;

int main(){
    int a[4];
    int ans;
    string s;
    cin >> s;
    int n=s.size();
    for(int i=0;i<n;i++){
        a[i]=stoi(s.substr(i,1));
    }

    for(int i=0;i<(1<<(n-1));i++){
        int tmp=a[0];
        for(int j=0;j<n-1;j++){
            if(i>>j & 1){
                tmp+=a[j+1];
            }else{
                tmp-=a[j+1];
            }
        }
        if(tmp==7){
            ans=i;
            break;
        }
    }

    cout << a[0];
    for(int i=1;i<n;i++){
        if(ans>>(i-1) & 1){
            cout << '+';
        }else{
            cout << '-';
        }
        cout << a[i];
    }
    cout << "=7";

    return 0;
}
