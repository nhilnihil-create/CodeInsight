#include<cstdio>
#include<utility>
#include<cmath>
#include<algorithm>

using namespace std;

int main(){
    const int INF = 1000000001;
    int n, k;
    scanf("%d %d", &n, &k);
    long int x[n], y[n];
    for(int i = 0; i < n; i++){
        long int x1, y1;
        scanf("%ld %ld", &x1, &y1);
        x[i] = x1;
        y[i] = y1;
    }
    long int min = 9000000000000000000;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int t = 0; t < n; t++){
                for(int l = 0; l < n; l++){
                    long int x_lst[] = {x[i], x[j]};
                    long int y_lst[] = {y[t], y[l]};
                    int count = 0;
                    long int xmin = INF;
                    long int xmax = -INF;
                    long int ymin = INF;
                    long int ymax = -INF;
                    for(int m = 0; m < 2; m++){
                        if (x_lst[m] > xmax){
                            xmax = x_lst[m];
                        }
                        if (x_lst[m] < xmin){
                            xmin = x_lst[m];                            
                        }
                        if (y_lst[m] > ymax){
                            ymax = y_lst[m];                            
                        }
                        if (y_lst[m] < ymin){
                            ymin = y_lst[m];
                        }
                    }
                    for(int m = 0; m < n; m++){
                        if (xmin <= x[m] && x[m] <= xmax && ymin <= y[m] && y[m] <= ymax) count++;
                    }
                    // printf("%ld %ld %ld %ld\n", xmax, xmin, ymax, ymin);
                    // printf("%d %d\n",count, k);
                    if (count >= k){
                        long int area = (xmax - xmin) * (ymax - ymin);
                        
                        if (min > area) min = area;
                    }
                    
                }
            }
            
        }
        
    }
    printf("%ld\n", min);
}