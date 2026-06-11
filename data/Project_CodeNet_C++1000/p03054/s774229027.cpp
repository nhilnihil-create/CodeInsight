#include <iostream>

using namespace std;

int main(){
  
    int H,W,N,r,c;
    int L,R,U,D;
    int i;
    string First,Second;

    cin>>H>>W>>N;
    cin>>r>>c;
    cin>>First>>Second;
    L=R=U=D=0;
    for (i=N-1;i>=0;i--){
        if(Second[i]=='U') D=(D-1>0)?D-1:0;
        if(Second[i]=='D') U=(U-1>0)?U-1:0;
        if(Second[i]=='L') R=(R-1>0)?R-1:0;
        if(Second[i]=='R') L=(L-1>0)?L-1:0;

        if(First[i]=='U') U++;
        if(First[i]=='D') D++;
        if(First[i]=='R') R++;
        if(First[i]=='L') L++;

        if (L+R>=W || U+D>=H){
            cout<<"NO\n";
            return 0;
        }
    }

    if(L>=c || c+R>W || U>=r || r+D>H)
        cout<<"NO\n";
    else
        cout<<"YES\n";

    return 0;
}