#include <iostream>
using namespace std;

int main(void){
    int n;
    cin >> n;
    
    int a;
    int max = 0, min = 0;
    int max_idx = 1, min_idx = 1;
    int i;
    for(i = 1; i <= n; i++){
        cin >> a;
        if(a > max){
            max = a;
            max_idx = i;
        }
        if(a < min){
            min = a;
            min_idx = i;
        }
    }
    
    bool ispos;
    if(min >= 0){
        ispos = true;
    }else if(max <= 0){
        ispos = false;
    }else{
        ispos = (max >= abs(min)) ? true : false;
    }
    
    cout << (n - 1) * 2 << endl;
    
    if(ispos){
        for(i = 1; i <= n; i++){
            if(i != max_idx){
                printf("%d %d\n", max_idx, i);
            }
        }
        for(i = 1; i < n; i++){
            printf("%d %d\n", i, i + 1);
        }
    }else{
        for(i = 1; i <= n; i++){
            if(i != min_idx){
                printf("%d %d\n", min_idx, i);
            }
        }
        for(i = n - 1; i >= 1; i--){
            printf("%d %d\n", i + 1, i);
        }
    }
    
    return 0;
}
