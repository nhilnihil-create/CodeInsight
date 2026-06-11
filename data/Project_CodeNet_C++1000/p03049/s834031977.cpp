#include<bits/stdc++.h>
using namespace std;

int main(){
    int i=0,j=0,N=0,AB=0,A=0,B=0,BA=0;
    cin >> N;
    string s;
    for(i=0;i<N;i++){
        cin >> s;
        if(s[0]=='B'&&s[s.size()-1]!='A')B++;
        if(s[0]!='B'&&s[s.size()-1]=='A')A++;
        if(s[0]=='B'&&s[s.size()-1]=='A')BA++;
        for(j=0;j<s.size()-1;j++){
            if(s[j]=='A'&&s[j+1]=='B')AB++;
        }
        //cout << A << " " << B << " " << AB << " " << BA << endl;
    }
    if(BA==0)cout << AB + min(A,B) << endl;
    else if(A==0&&B==0)cout << AB + BA - 1 << endl;
    else cout << AB + BA + min(A,B) << endl;
    return 0;
}