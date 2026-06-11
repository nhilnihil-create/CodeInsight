#include<bits/stdc++.h>
#include<vector>
#include<cmath>
#include<string>
using namespace std;
#define vc                      vector<int>
#define vcvc                    vector<vector<int>>
#define vcl                     vector<long int>
#define vccl                    vector<long long int>
#define pb(a)                   push_back(a)
#define rep(i,a)                for(int i=0;i<a;i++)
#define repl(i,a)               for(long int i=0;i<a;i++)
#define mod                     1000000007
#define cin2(a,b)                cin>>a>>b
#define cin3(a,b,c)              cin>>a>>b>>c
#define cin4(a,b,c,d)            cin>>a>>b>>c>>d
#define seti                    set<int>
#define setl                 set<long int>
#define uset                 unordered_set<int>
#define usetl                             unordered_set<long int>
long int binarySearch(vector<long int> arr, long int l, long int r, long int x)
{
    if (r > l) {
        long int mid = l + (r - l) / 2;

        // If the element is present at the middle
        // itself
        if (arr[mid] == x)
            return mid;
        // if ((l == r) && (arr[mid] != x))return -1;

        // If element is smaller than mid, then
        // it can only be present in left subarray
        else if (arr[mid] > x)
            return binarySearch(arr, l, mid, x);

        // Else the element can only be present
        // in right subarray
        else if (arr[mid] < x)return binarySearch(arr, mid + 1, r, x);
    }

    // We reach here when element is not
    // present in array
    return -1;
}

void merge(vc &arr,  int l, int m, int r, vc &index)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
    int L[n1], R[n2];
    int l1[n1], r1[n2];

    // int l1[n1], r1[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) {
        L[i] = arr[l + i];
        l1[i] = index[l + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
        r1[j] = index[m + 1 + j];
    }

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] < R[j])
        {
            arr[k] = L[i];
            index[k] = l1[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            index[k] = r1[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        index[k] = l1[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        index[k] = r1[j];

        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(vc &arr, int l, int r, vc &index )
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m, index);
        mergeSort(arr, m + 1, r, index);

        merge(arr, l, m, r, index);
    }
}
double min1(double a, double b) {
    if (a < b)return a; return b;
}

long int max(long int a, long int b) {
    if (a > b)return a;
    return b;
}
int gcd(int a, int b) { if (b == 0)return a; else return gcd(b, a % b);}
bool binary(long long int n, long int k, vc &ans) {
    if (n == 0)return true;
    if (n == 1) {
        if (ans[0] == 0) {
            ans[0]++;
            return true;
        }
        else return false;

    }
    int count = 0;
    while (n) {
        int temp = n % k;
        if (temp != 0) {
            if ((temp > 1) || (ans[count]))return false;
            else ans[count]++;
        } count++;
        n = n / k;
    }
    return true;


}
void solve()
{
    long int n;
    cin >> n;
    vcl num(n);
    repl(i, n)cin >> num[i];
    long int ans = 0;
    for (long int i = 0; i < n - 1; i++) {
        if (num[i] == num[i + 1]) {
            num[i + 1] = 1e5 + 1;
            ans++;
            i = i + 1;
        }

    }
    cout << ans << endl;







}
int main() {
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    solve();



}