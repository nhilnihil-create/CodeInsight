#include<bits/stdc++.h>
using namespace std;
void display()
{
    int a, b, c, d;
    cin>>a>>b>>c>>d;
    puts(a+b == c+d ? "Balanced" : a+b > c+d ? "Left" : "Right");
}
int main(void)
{
    display();
}
