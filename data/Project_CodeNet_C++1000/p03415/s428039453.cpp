/*
   * * * * *       *        * * * * * * * * * * * * * * * * * * * * * * * *     * * * * * * *               * *               * * * * * * * * * *
   * * * * *      * *       * * * * * * * * * * * * * * * * * * * * * *    *    * * * * * * *              * * *             * ** * * * * * * * * *
   * *           * * *            * *     * *     * *      * *          * * *   * * *       *             * * * *           * * * *       * *    * *
   * * * * *    * * * *           * *     * *     * *       * * * * * * *  * *  * * * * * * *            * * * * *         * *  * *       * * * * *
   * * * * *   * * * * *          * *     * *     * *        * * * * ** *   * * * * * * * * *           * * * * * *       * *   * * * *   * * * *
         * *  * * * * * *   * *   * *     * *     * *       * * * * * * *    * ** *     * * *          * * * * * * *     * *    * * * *   * *  * *
         * * * *       * *  * *   * *     * *     * *      * *          *     * * *     * * *         * *       * * *   * *     * *       * *   * *
   * * * * ** *         * * * * * * * * * * * * * * * * * * * * * * * * *      *  * * * * * * * * * ** *         * * * * *      * * * * * * *    * *
   * * * * * *           * ** * * * * * * * * * * * * * * * * * * * * * *       * * * * * * * * * * * *           * * * *       * * * * * * *     * *
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <set>
#define ll long long
#define rep(i, a, b) for (int i = int(a); i <= int(b); i++)
#define sz(a) int((a).size())
#define shit while(t--)
#define fr for(int i=0;i<n;i++)
int maxo=1e9+7;
using namespace std;
int arr[95];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    char a[4],b[4],c[4];
    for(int i=0;i<3;i++)
    {
        cin>>a[i]>>b[i]>>c[i];
    }
    cout<<a[0]<<b[1]<<c[2];
    return 0;
}

