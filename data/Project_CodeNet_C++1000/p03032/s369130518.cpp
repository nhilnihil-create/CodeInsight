#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX_N 50
int v[MAX_N];
int n;
int k;

int favour_left[MAX_N][MAX_N + 1];
int favour_right[MAX_N][MAX_N + 1];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    int i;
    for(i = 0; i < n; ++i){
        cin >> v[i];
    }
    int j;
    for(i = 1; i <= n; ++i){
        priority_queue<int, vector<int>, greater<int> > q;
        int max_sum = 0;
        for(j = 0; j < i; ++j){
            max_sum += v[j];
            q.push(v[j]);
        }
        favour_left[i - 1][i] = max_sum;
        for(j = i; j < n; ++j){
            if(v[j] > q.top()){
                max_sum -= q.top();
                q.pop();
                max_sum += v[j];
                q.push(v[j]);
            }
            favour_left[j][i] = max_sum;
        }
    }
    for(i = 1; i <= n; ++i){
        priority_queue<int, vector<int>, greater<int> > q;
        int max_sum = 0;
        for(j = 0; j < i; ++j){
            max_sum += v[n - 1 - j];
            q.push(v[n - 1 - j]);
        }
        favour_right[i - 1][i] = max_sum;
        for(j = i; j < n; ++j){
            if(v[n - 1 - j] > q.top()){
                max_sum -= q.top();
                q.pop();
                max_sum += v[n - 1 - j];
                q.push(v[n - 1 - j]);
            }
            favour_right[j][i] = max_sum;
        }
    }
    int max_favour = 0;
    int p, q;
    for(i = 0; i < n; ++i){
        for(p = i + 1; p >= 0; --p){
            int op_left = i + 1 + (i + 1 - p);
            if(op_left > k){
                break;
            }
            max_favour = max(max_favour, favour_left[i][p]);
        }
    }
    for(j = 0; j < n; ++j){
        for(q = j + 1; q >= 0; --q){
            int op_right = j + 1 + (j + 1 - q);
            if(op_right > k){
                break;
            }
            max_favour = max(max_favour, favour_right[j][q]);
        }
    }
    for(i = 0; i < n; ++i){
        for(j = 0; j < n && i + j + 1 < n; ++j){
            for(p = i + 1; p >= 0; --p){
                int op_left = i + 1 + (i + 1 - p);
                if(op_left > k){
                    break;
                }
                for(q = j + 1; q >= 0; --q){
                    int op_right = j + 1 + (j + 1 - q);
                    if(op_left + op_right > k){
                        break;
                    }
                    max_favour = max(max_favour, favour_left[i][p] + favour_right[j][q]);
                }
            }
        }
    }
    cout << max_favour << '\n';
    return 0;
}
