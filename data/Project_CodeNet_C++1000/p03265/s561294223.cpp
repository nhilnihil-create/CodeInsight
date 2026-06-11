#include <bits/stdc++.h>
using namespace std;
int main() {
int x1,y1,x2,y2;
scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
int vx=x2-x1, vy=y2-y1;
int x3,y3,x4,y4;
x3=x2 + -vy;
y3=y2 + vx;
x4=x3 -vx;
y4=y3-vy;
printf("%d %d %d %d",x3,y3,x4,y4);
cout << endl;
    return 0;
}