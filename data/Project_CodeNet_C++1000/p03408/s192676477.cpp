#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    string s[n];
    int i,j;
    for(i=0;i<n;i++)
        cin >> s[i];
    int m;
    cin >> m;
    string t[m];
    for(i=0;i<m;i++)
        cin >> t[i];

    int counter[n];
    for(i=0;i<n;i++)
        counter[i]=0;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(s[i]==s[j])
                counter[i]++;
        }
        for(j=0;j<m;j++){
            if(s[i]==t[j])
                counter[i]--;
        }
    }

    int max=counter[0];
    for(i=0;i<n;i++){
        if(max<counter[i])
            max=counter[i]; 
    }
    if(max<0)
        max=0;
    cout << max << endl;
}
