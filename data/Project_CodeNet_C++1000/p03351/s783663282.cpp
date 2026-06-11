#include<bits/stdc++.h>
using namespace std;
void display()
{
    int a, b, c, d;
    cin>>a>>b>>c>>d;
    puts( abs(a-c) <= d  ? "Yes" :  abs(a-b) <=d && abs(b-c) <=d ? "Yes" :"No");
    cout<<endl;
}
int main(void)
{
    display();
}