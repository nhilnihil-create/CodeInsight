#include <iostream>
using namespace std;
int main(void){
    // Your code here
    int a, b;scanf("%d%d",&a,&b);
    int c[b], d[b];
    for (int i =0; i<b; i++){scanf("%d%d",&c[i],&d[i]);}
    
    // 最小値と最大値の区切りを更新するアルゴリズム
    int start = c[0];
    int end = d[0];
    for (int j = 1; j < b; j++){
        if (c[j] > start){
            start = c[j];
        }
        if (d[j] < end){
            end = d[j];
        }
    }
    
    int result = max(0, (end - start + 1));
    printf("%d", result);

}