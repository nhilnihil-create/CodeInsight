#include <bits/stdc++.h>
using namespace std;
int main() {
    string a,b;
    cin>>a>>b;
    int A,B;
    A=a.length(),B=b.length();
    vector <vector <int>> answer(A+1,vector<int>(B+1,0));
    for(int i=1;i<=A;i++){
        for(int j=1;j<=B;j++){
            if(a[i-1]==b[j-1])answer[i][j]=answer[i-1][j-1]+1;
            else answer[i][j]=max(answer[i][j-1],answer[i-1][j]);
        }
    }
    int x=A,y=B;
    string s="";
    while(x!=0 && y!=0){
        if(answer[x][y]==answer[x][y-1]){
            y--;
            continue;
        }
        if(answer[x][y]==answer[x-1][y]){
            x--;
            continue;
        }
        s=a[x-1]+s;
        x--;y--;
    }
    cout<<s<<endl;
	return 0;
}
