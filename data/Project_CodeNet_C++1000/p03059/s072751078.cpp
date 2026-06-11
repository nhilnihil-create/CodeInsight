#include <iostream>
using namespace std;
int main()
{
    int a,b;
    double t;
    cin>>a>>b>>t;
    t+=0.5;
  
    std::cout << int(t/a)*b << std::endl;
}
