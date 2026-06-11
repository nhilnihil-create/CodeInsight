#include <iostream>
using namespace std;
int main(){
    int a, b, c,  
        d, e, f,  
        g, h, i;
    cin >> a >> b >> c >> d >> e >> f >> g >> h >> i;
    if(a-b!=d-e||d-e!=g-h||a-b!=g-h||
       b-c!=e-f||e-f!=h-i||h-i!=b-c||
       c-a!=f-d||f-d!=i-g||i-g!=c-a||
       a-d!=b-e||b-e!=c-f||c-f!=a-d||
       d-g!=e-h||e-h!=f-i||f-i!=d-g||
       g-a!=h-b||h-b!=i-c||i-c!=g-a||
       a+e+i!=c+d+h||a+e+i!=b+f+g||g+b+f!=c+d+h||
       c+e+g!=f+h+a||c+e+g!=b+d+i||f+h+a!=b+d+i
    ){
        puts("No");
        return 0;
    }
    puts("Yes");
    return 0;
}