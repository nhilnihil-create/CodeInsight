#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#define ll long long
#define pi (acos(-1))

int main()
{

int r;
int D,x;
ll tmp;

std::cin>>r>>D>>x;
tmp=x;
for(int i=0;i!=10;++i){
tmp=r*tmp -D;
std::cout<<tmp<<std::endl;
}





    return 0;
}
