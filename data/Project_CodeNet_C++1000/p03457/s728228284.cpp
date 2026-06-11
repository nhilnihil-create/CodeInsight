    #include <stdio.h>
    #include <iostream>
    using namespace std;
     
    int main(){
        int N;
        scanf("%d", &N);
        int t, x, y;
        int t_pre = 0, x_pre = 0, y_pre = 0;
        for(int i = 0; i < N;i++){
            scanf("%d %d %d", &t, &x, &y);
            if(!((t - t_pre >= abs(x - x_pre)+ abs(y -y_pre)) && ((t - t_pre - (x-x_pre)  - (y-y_pre)) % 2 == 0))){
                printf("No");
                return 0;
            }
            t_pre = t;
            x_pre = x;
            y_pre = y;
        }
        printf("Yes");
        return 0;
    }