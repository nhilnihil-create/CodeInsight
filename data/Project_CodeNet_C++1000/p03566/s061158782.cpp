#include<cstdio>

using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    int t[n];
    int v[n+1];
    for (int i = 0; i < n; i++) scanf("%d", &t[i]);
    for (int i = 0; i < n; i++) scanf("%d", &v[i]);
    v[n] = 0;
    int time[n];
    time[0] = t[0];
    for (int i = 1; i < n; i++) time[i] = time[i-1] + t[i];

    // for (int i = 0; i < n; i++) printf("%d\n",time[i]);

    double speed = 0.5;
    double T = 0.5;
    double ans = 0.5 * 0.5 * 0.5;
    for (double i = 0.5; i < time[n-1]; i += 0.5){
        for (int j = 0; j < n; j++){
            if (time[j] > i){
                bool flag = false;
                for (int k = j; k < n; k++){
                    if (v[k+1] + (time[k] - i) <= speed){
                        // puts("1");

                        ans += (speed + speed - 0.5) * 0.5 * 0.5;
                        speed -= 0.5;
                        flag = true;
                        
                        // printf("%f\n", ans);
                        break;
                    }
                }
                if (flag) break;
                if (speed == v[j]){
                    ans += speed / 2;
                    // printf("%f\n", ans);
                    break;
                }
                else {

                }

                ans += (speed + speed + 0.5) * 0.5 * 0.5;
                speed += 0.5;
                // printf("%f\n", ans);
                break;
            }
        }
        // T++;
        // printf("T = %f\n", i);
        // printf("speed = %f\n", speed);

    }
    printf("%f\n", ans);

}