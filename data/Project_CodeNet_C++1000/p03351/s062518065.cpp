#include<bits/stdc++.h>
using namespace std;
void display()
{
    int a, b, c, d;
    cin>>a>>b>>c>>d;
    puts(abs(a-c) <= d || abs(a-b) <= d && abs(b-c) <=d ? "Yes": "No");
}
int main(void)
{
    display();
}