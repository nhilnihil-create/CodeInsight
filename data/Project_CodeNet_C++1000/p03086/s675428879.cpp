#include<bits/stdc++.h>
using namespace std;

int main(){
    string s,s1 = "ACGT";
    getline(cin,s);
    int max = 0,cnt, i = 0;
    while(i<s.length()){
        cnt = 0;
        int j = i;
        while(j<s.length() && (int)s1.find(s[j]) != -1){
            j++;
            cnt++;
        }
        i = (i == j) ? i+1 : j;
        max = (cnt>max)? cnt : max;
    }
    cout<<max;
    return 0;
}