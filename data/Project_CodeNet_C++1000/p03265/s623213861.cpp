#include <bits/stdc++.h>
#include <math.h>
using namespace std;
void ABC100(void);
void ABC101(void);
void ABC102(void);
void ABC103(void);
void ABC104(void);
void ABC105(void);
void ABC106(void);
void ABC107(void);
void ABC108(void);
void ABC109(void);

int main(void){
    ABC108();
}

void ABC108(){
    int x1,x2,y1,y2,dx,dy;
    cin>>x1>>y1>>x2>>y2;
    dx=x2-x1;
    dy=y2-y1;
    cout<<x2-dy<<" "<<y2+dx<<" "<<x2-dy-dx<<" "<<y2+dx-dy<<endl;
}
