/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <cmath>
using namespace std;

struct point{
    int x, y, alt;
};

int main(){
    int n, h, pos, count = 0;
    point a[100];
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i].x >> a[i].y >> a[i].alt;
        if(a[i].alt!=0){
            pos = i;
        }
    }
    for(int i=0;i<=100;i++){
        for(int j=0;j<=100;j++){
            h = a[pos].alt + abs(a[pos].x-i) + abs(a[pos].y-j);
            for(int k=0;k<n;k++){
                if((h-abs(a[k].x-i)-abs(a[k].y-j))==a[k].alt){
                    count ++;
                }
                else if((h-abs(a[k].x-i)-abs(a[k].y-j))<0&&a[k].alt==0){
                    count ++;
                }
            }
            if(count==n){
                cout << i << " " << j << " " << h;
                break;
            }
            count = 0;
        }
        if(count==n){
            break;
        }
    }
    return 0;
}